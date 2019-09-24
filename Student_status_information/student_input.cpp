#include <iostream>
#include "tinyxml.h"
#include <string>
#include <map>
//#include <cctype>
using namespace std;

class XMLFile
{
public:
	XMLFile(const char *xmlFileName);
	~XMLFile();

public:
	void CreateXML();//创建XML文件
	void ReadXML();//读取XML文件完整内容
	void ReadDeclaration(string &version, string &encoding, string &standalone);//读取XML声明
	bool FindNode(TiXmlElement *pRoot, const string nodeName, TiXmlElement *&pNode);//根据节点名，判断节点是否存在
	bool GetNodeText(const string nodeName, const char *&text);//根据节点名，获取该节点文本
	bool GetNodeAttribute(const string nodeName, map<string, string> &mapAttribute);//获取根据节点名， 获取节点属性
	bool DeleteNode(const string nodeName);//根据节点名，删除节点
	bool modifyText(const string nodeName, const string text);//修改节点文本
	bool modifyAttribution(const string nodeName, map<string, string> &mapAttribute);//修改节点属性
	bool AddNode(const string nodeName, const char * newNodeName, const char *text, const char *name, const char* gender, const char* id, const char* dormitory, const char* number);
private:
	char *m_xmlFileName;
	TiXmlDocument *m_pDocument;
	TiXmlDeclaration *m_pDeclaration;
};

XMLFile::XMLFile(const char *xmlFileName)
{
	m_xmlFileName = new char[20];
	strcpy(m_xmlFileName, xmlFileName);
	m_pDocument = NULL;
	m_pDeclaration = NULL;
}

XMLFile::~XMLFile()
{
	if (m_xmlFileName != NULL)
		delete m_xmlFileName;

	if (m_pDocument != NULL)
		delete m_pDocument;

	if (m_pDeclaration != NULL)
		delete m_pDeclaration;
}

void XMLFile::CreateXML()
{
	//创建XML文档指针
	m_pDocument = new TiXmlDocument(m_xmlFileName);
	if (NULL == m_pDocument)
	{
		return;
	}

	//声明XML
	m_pDeclaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	if (NULL == m_pDeclaration)
	{
		return;
	}
	m_pDocument->LinkEndChild(m_pDeclaration);

	//创建根节点
	string xmlFileName = m_xmlFileName;
	string rootName = (xmlFileName.substr(0, xmlFileName.find(".")));//根节点元素名为文件名去掉.xml
	TiXmlElement *pRoot = new TiXmlElement(rootName.c_str());
	if (NULL == pRoot)
	{
		return;
	}
	//关联XML文档，成为XML文档的根节点
	m_pDocument->LinkEndChild(pRoot);

	TiXmlText *pText = new TiXmlText("学籍信息");
	pRoot->LinkEndChild(pText);

	//创建孩子节点
	TiXmlElement *pStudent = new TiXmlElement("Student");
	if (NULL == pStudent)
	{
		return;
	}
	TiXmlText *pStuText = new TiXmlText("machine");
	pStudent->LinkEndChild(pStuText);

	//pStudent->SetAttribute("name", "王艺宸");
	//pStudent->SetAttribute("gender", "男");
	//pStudent->SetAttribute("id", "M201970519");
	//pStudent->SetAttribute("dormitory", "412");
	//pStudent->SetAttribute("number", "18398621916");

	//关联根节点，成为根节点的孩子节点
	pRoot->LinkEndChild(pStudent);

	m_pDocument->SaveFile(m_xmlFileName);
}

//读取XML文件完整内容
void XMLFile::ReadXML()
{
	if (m_xmlFileName == NULL)
	{
		cout << " null " << endl;
		return;
	}
	m_pDocument->LoadFile(m_xmlFileName);
	m_pDocument->Print();
}

//读取XML声明，例如：<?xml version="1.0" encoding="UTF-8" ?>
void XMLFile::ReadDeclaration(string &version, string &encoding, string &standalone)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlNode *pNode = m_pDocument->FirstChild();
	if (NULL != pNode)
	{
		//获取声明指针
		m_pDeclaration = pNode->ToDeclaration();

		if (NULL != m_pDeclaration)
		{
			version = m_pDeclaration->Version();
			encoding = m_pDeclaration->Encoding();
			standalone = m_pDeclaration->Standalone();
		}
	}
}

//根据节点名，判断节点是否存在
bool XMLFile::FindNode(TiXmlElement *pRoot, const string nodeName, TiXmlElement *&pNode)
{
	const char *value = pRoot->Value();
	if (strcmp(pRoot->Value(), nodeName.c_str()) == 0)
	{
		pNode = pRoot;
		return true;
	}

	TiXmlElement *p = pRoot;
	for (p = p->FirstChildElement(); p != NULL; p = p->NextSiblingElement())
	{
		FindNode(p, nodeName, pNode);
		return true;
	}

	return false;
}

//根据节点名，获取该节点文本
bool XMLFile::GetNodeText(const string nodeName, const char *&text)
{
	m_pDocument->LoadFile(m_xmlFileName);
	if (NULL == m_pDocument)
	{
		return false;
	}

	TiXmlElement *pRoot = m_pDocument->RootElement();
	const char *value = pRoot->Value();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		text = pNode->GetText();
		return true;
	}

	return false;
}

//获取根据节点名， 获取节点属性
bool XMLFile::GetNodeAttribute(const string nodeName, map<string, string> &mapAttribute)
{
	m_pDocument->LoadFile(m_xmlFileName);
	if (NULL == m_pDocument)
	{
		return false;
	}

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		TiXmlAttribute *pAttr = NULL;
		for (pAttr = pNode->FirstAttribute(); pAttr != NULL; pAttr = pAttr->Next())
		{
			string name = pAttr->Name();
			string value = pAttr->Value();
			mapAttribute.insert(make_pair(name, value));
		}

		return true;
	}

	return false;
}

//删除节点
bool XMLFile::DeleteNode(const string nodeName)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		if (pNode == pRoot)
		{//如果是根节点
			m_pDocument->RemoveChild(pRoot);
			m_pDocument->SaveFile(m_xmlFileName);
			return true;
		}
		else
		{//子节点
			TiXmlNode *parent = pNode->Parent();//找到该节点的父节点
			if (NULL == parent)
			{
				return false;
			}

			TiXmlElement *parentElem = parent->ToElement();
			if (NULL == parentElem)
			{
				return false;
			}
			parentElem->RemoveChild(pNode);
			m_pDocument->SaveFile(m_xmlFileName);
			return true;
		}
	}

	return false;
}

//修改节点文本
bool XMLFile::modifyText(const string nodeName, const string text)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		//pNode->Clear();//删除原节点下的其他元素
		TiXmlText *pText = new TiXmlText(text.c_str());
		pNode->LinkEndChild(pText);
		m_pDocument->SaveFile(m_xmlFileName);
		return true;
	}

	return false;
}

//修改节点属性
bool XMLFile::modifyAttribution(const string nodeName, map<string, string> &mapAttribute)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		TiXmlAttribute *pAttr = pNode->FirstAttribute();
		char *strName = NULL;
		for (; pAttr != NULL; pAttr = pAttr->Next())
		{
			strName = const_cast<char *>(pAttr->Name());
			for (auto it = mapAttribute.begin(); it != mapAttribute.end(); ++it)
			{
				if (strName == it->first)
				{
					pNode->SetAttribute(strName, it->second.c_str());
				}
			}
		}
		m_pDocument->SaveFile(m_xmlFileName);
		return true;
	}

	return false;
}

//在名为nodeName的节点下插入子节点
bool XMLFile::AddNode(const string nodeName, const char * newNodeName, const char *text, const char *name, const char* gender, const char* id, const char* dormitory, const char* number)
{
	m_pDocument->LoadFile(m_xmlFileName);

	TiXmlElement *pRoot = m_pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pNode = NULL;
	if (FindNode(pRoot, nodeName, pNode))
	{
		TiXmlElement *pNewNode = new TiXmlElement(newNodeName);
		TiXmlText *pNewText = new TiXmlText(text);
		pNewNode->SetAttribute("name", name);
		pNewNode->SetAttribute("gender", gender);
		pNewNode->SetAttribute("id", id);
		pNewNode->SetAttribute("dormitory", dormitory);
		pNewNode->SetAttribute("number", number);

		pNewNode->LinkEndChild(pNewText);
		pNode->InsertEndChild(*pNewNode);
		m_pDocument->SaveFile(m_xmlFileName);
		return true;
	}

	return false;
}