// AttributeParset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <map>

class Attribute
{
	
public:
	Attribute()
	= default;
		
	void SetName(std::string p_name) { m_name = std::move(p_name); }
	std::string Name() const { return m_name; }

	void AddAttribute (std::pair<std::string, std::string > _attribute)
	{
		m_attributes.push_back(std::move(_attribute));
	}

	void AddTag(Attribute* _subTag) {
		sub_tags.insert({ _subTag->Name(), _subTag });
	}

	
	void AddParent(const std::shared_ptr<Attribute>& _tag) {
		_parent = _tag;
	}

	int NumberOfTags() const
	{
		return sub_tags.size();
	}
	
private:
	std::shared_ptr<Attribute> _parent;
	std::string m_name;
	std::vector< std::pair<std::string, std::string > > m_attributes;

	std::map<std::string, Attribute*> sub_tags;
};

enum class HrmlLineProcessing
{
	None,
	GettingName,
	ProcessingName,
	GettingAttributeName,
	ProcessingAttributeName,
	GettingAttributeValue,
	ProcessingAttributeValue,
	GettingTagEnd
};

HrmlLineProcessing TransitionState(HrmlLineProcessing processState)
{
	switch (processState) {
	case HrmlLineProcessing::None: return HrmlLineProcessing::GettingName;
		case HrmlLineProcessing::GettingName: return HrmlLineProcessing::ProcessingName;
		case HrmlLineProcessing::ProcessingName: return HrmlLineProcessing::GettingAttributeName;
		case HrmlLineProcessing::GettingAttributeName: return HrmlLineProcessing::ProcessingAttributeName;
		case HrmlLineProcessing::ProcessingAttributeName: return HrmlLineProcessing::GettingAttributeValue;
		case HrmlLineProcessing::GettingAttributeValue: return HrmlLineProcessing::ProcessingAttributeValue;
		case HrmlLineProcessing::ProcessingAttributeValue: return HrmlLineProcessing::GettingTagEnd;
		case HrmlLineProcessing::GettingTagEnd: return HrmlLineProcessing::None;
		default: ;
	}
	return HrmlLineProcessing::None;
}

Attribute processHRML(std::vector<std::string> hrml)
{
	constexpr char StateChangeCharacters[] = { "< =\"/" };

	Attribute _hrmlRoot;
	std::unique_ptr<Attribute> _hrmlChild = std::make_unique<Attribute>(_hrmlRoot);

	auto hrmlLineState = HrmlLineProcessing::GettingName;
		
	for (size_t i = 0; i < (hrml.size() / 2) + 1; ++i)
	{
		std::string name;
		std::string value;
		auto lastCharCausedStateChange = false;
		for (auto&& var : hrml.at(i))
		{
			if (std::strchr(StateChangeCharacters, var) != nullptr)
			{
				if (!lastCharCausedStateChange)
				{
					hrmlLineState = TransitionState(hrmlLineState);
				}

				if (var == '<') {
					hrmlLineState = HrmlLineProcessing::GettingName;

					if (_hrmlRoot.NumberOfTags() != 0) {

					}
				}

				if (var == '/') {
					if (_hrmlChild.get() != &_hrmlRoot) {
						auto _hrmlTempChild = new Attribute();
						_hrmlTempChild->AddParent(std::move(_hrmlChild));
						_hrmlChild->AddTag(_hrmlTempChild);
						//_hrmlChild = _hrmlTempChild;
					}
				}
			}

			switch (hrmlLineState) {
			case HrmlLineProcessing::None: break;
			case HrmlLineProcessing::GettingName: break;
			case HrmlLineProcessing::ProcessingName:
				name += var;
				break;
			case HrmlLineProcessing::GettingAttributeName:
				_hrmlChild->SetName(name);
				name.clear();
				break;
			case HrmlLineProcessing::ProcessingAttributeName:
				name += var;
				break;
			case HrmlLineProcessing::GettingAttributeValue: break;
			case HrmlLineProcessing::ProcessingAttributeValue:
				value += var;
				break;
			case HrmlLineProcessing::GettingTagEnd:
				_hrmlChild->AddAttribute(std::make_pair(name, value));
				name.clear();
				value.clear();
				break;
			default:;
			}
		}
	}
	return _hrmlRoot;
}

/*
 				switch (HrmlLineState) {
				case HrmlLineProcessing::GettingName:
					throw X;
					break;
				case HrmlLineProcessing::ProcessingName: break;
				case HrmlLineProcessing::GettingAttributeName: break;
				case HrmlLineProcessing::ProcessingAttributeName: break;
				case HrmlLineProcessing::GettingAttributeValue: break;
				case HrmlLineProcessing::ProcessingAttributeValue: break;
				default:;
				}
 */
std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

std::vector<std::string> GetLines(int q)
{
	std::vector<std::string> _hrml;
	std::string str;

	while (q--)
	{
		getline(std::cin, str);
		_hrml.push_back(str);
	}

	return _hrml;
}

std::pair<int, int> GetQuery()
{
	int n, q;

	std::cin >> n >> q;
	std::cin.ignore(1000, '\n');

	return std::make_pair(n, q);
}

int main()
{
    std::cout << "Enter N & Q\n";

		auto nAndq = GetQuery();

		std::cout << "Enter HRML " << nAndq.first << "\n";
		auto hrml = GetLines(nAndq.first);

		std::cout << "Enter Queries " << nAndq.second << "\n";
		auto queries = GetLines(nAndq.second);

    try
    {
			processHRML(hrml);	    
    }
    catch (int e)
    {
			std::cout << "Error parsing " << e;
    }
	
    std::cout << "nAndq " << nAndq.first << ":" << nAndq.second << std::endl;
    for (auto const & oneLine : hrml)
    {
			std::cout << oneLine << "\n";
    }

		std::cout << "Queries " << std::endl;
		for (auto const& oneLine : queries)
		{
			std::cout << oneLine << "\n";
		}
	
    std::cout << "\nhit a key" << std::endl;
    std::cin.get();
}
