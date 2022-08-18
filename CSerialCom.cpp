#include "CSerialCom.h"

BOOL CSerialCom::OpenPort(CString portName)
{
	portName = "//./" + portName;

	hComm = CreateFile(
		portName,					  //name of the port we want to open
		GENERIC_READ | GENERIC_WRITE, //access type: read, write, both
		0,				//sharedMode: must be opened with exclusive access
		0,				//security attributes
		OPEN_EXISTING,  //Creation Dispositin: must be OPEN_EXISTING
		0,				// flag attributes: not Overlaped I/O
		0);				//hTemplate File: must be 0 for comm devices


	if (hComm == INVALID_HANDLE_VALUE){
		return FALSE;
	}
	else
	{
		return TRUE;
	}

}

BOOL CSerialCom::ConfigurePort(DWORD BaudRate, BYTE ByteSize, DWORD fParity, BYTE stopBits)
{
	if( (m_bPortReady == GetCommState(hComm, &m_dcb) == 0) )
	{
		CloseHandle(hComm); //if we don't get the port's default property 
							//then we can use the window defined class function 
							//CloseHandle() to close the handle
		return FALSE;
	}
	//basically, we set the properties of the below properties
	m_dcb.BaudRate = BaudRate;
	m_dcb.ByteSize = ByteSize;
	m_dcb.fParity = fParity;
	m_dcb.StopBits = stopBits;
	// normally the bellow properties are asigned with the default
	m_dcb.fBinary = TRUE;
	m_dcb.fDsrSensitivity = false;
	m_dcb.Parity = NOPARITY;
	m_dcb.fOutX = false;
	m_dcb.fInX = false;
	m_dcb.fNull = false;
	m_dcb.fAbortOnError = TRUE;
	m_dcb.fOutxCtsFlow = FALSE;
	m_dcb.fOutxDsrFlow = false;
	m_dcb.fDtrControl = DTR_CONTROL_DISABLE;
	m_dcb.fRtsControl = RTS_CONTROL_DISABLE;
	m_dcb.fOutxCtsFlow = false;
	//now, after setting our defined properties, we need to check, if the set properties are true
	if( (m_bPortReady = SetCommState(hComm, &m_dcb) == 0) )
	{
		CloseHandle(hComm); //if we don't get the port's defined property we set, 
							//then we again close the handle using CloseHandle() 
		return FALSE;
	}
	return TRUE;
}