#pragma once
/*
	FileMapping.h �ڴ��ļ�ӳ��ͷ�ļ�
	���ܣ��ڴ�ӳ����ؽӿڣ��ɸ���������������չ
	�汾��1.0
	���ߣ�zhangfang 20140220
*/


#ifdef FILE_MAPPING_CPP
#define  DLLIMPORTOREXPORT	__declspec(dllexport)
#else
#define  DLLIMPORTOREXPORT	__declspec(dllimport)
#endif // FILE_MAPPING_CPP

const int MODE_READ_WRITE	=	0;
const int MODE_READ_ONLY	=	1;

const int FILEMAP_EXEC_SUCCESS	=	0;
const int FILEMAP_EXEC_FAILED	=	1;

class CFileMapImp;
class DLLIMPORTOREXPORT CFileMapping
{
public:
	CFileMapping();
	~CFileMapping();
public:
	/*�������ļ�����ӳ�䣬iOpentMode ΪMODE_READ_WRITE��Mode_Read_only
		����szOffset+szMapSize��С��ӳ���ļ�
	*/
	int CreateMapping(const char *pFileName, int iOpenMode, size_t szOffset, size_t szMapSize);
	/*�������ڵ��ļ�����ӳ�䣬szOffSetΪ��ĳ��λ�ÿ�ʼ��ӳ��szMapSize��С���ֽ�
		ע�⣺���szOffset����szMapSize�������(��Խ��)������ܵ���δ֪����
	*/
	int OpenMapping(const char *pFileName, int iOpenMode, size_t szOffset, size_t szMapSize);
	/*���ֶ��ر�ӳ��*/
	int CloseMap();
	/*��ȡӳ���С*/
	size_t GetSize();
	/*����ӳ��ĵ�ַ*/
	void *GetAddress();
	bool RemoveFile(const char *fileName);
private:
	CFileMapImp *m_pImp;
};