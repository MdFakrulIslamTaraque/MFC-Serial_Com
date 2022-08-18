#include<afxwin.h>
class CSerialCom:public CWnd
{
private:
	HANDLE hComm;

	DCB m_dcb; //DCB Class holds all the data of configuration
			   // and we are using an object of that DCB class
	
	BOOL m_bPortReady; //for storing the default object property of DCB to this variable
					// and if we get the default value using this BOOL type data, that indicates that
					//the opened portcan be reassigned the user defined properties 
public:
	BOOL ConfigurePort(DWORD BaudRate, BYTE ByteSize, DWORD fParity, BYTE stopBits);
	BOOL OpenPort(CString portName);
};
