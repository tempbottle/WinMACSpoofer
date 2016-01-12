#include "spoofHost.h"


	//Function that returns the current Host Name
	wstring spoofHost::getHostName(){

		wstring hostName;
		//Find HostName begin
		TCHAR buffer[256] = TEXT("");
		TCHAR szDescription[8][32] = { TEXT("NetBIOS"),
			TEXT("DNS hostname"),
			TEXT("DNS domain"),
			TEXT("DNS fully-qualified"),
			TEXT("Physical NetBIOS"),
			TEXT("Physical DNS hostname"),
			TEXT("Physical DNS domain"),
			TEXT("Physical DNS fully-qualified") };

		TCHAR szDescriptionCompare[1][32] = { TEXT("DNS hostname") };
		int cnf = 0;
		DWORD dwSize = sizeof(buffer);

		for (cnf = 0; cnf < ComputerNameMax; cnf++)
		{
			if (!GetComputerNameEx((COMPUTER_NAME_FORMAT)cnf, buffer, &dwSize))
			{
				_tprintf(TEXT("GetComputerNameEx failed (%d)\n"), GetLastError());
			}
			else _tprintf(TEXT("%s: %s\n"), szDescription[cnf], buffer);

			if (szDescription[cnf] == szDescription[1]){
				hostName = buffer;
			}
			dwSize = _countof(buffer);
			ZeroMemory(buffer, dwSize);
		}

		return hostName;

	}

	void spoofHost::setNewHostName(string changeHostName){

		HKEY hKey;

		LPCWSTR regPath = TEXT("SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters");
		LPCSTR newHostName = changeHostName.c_str();
		//convert LPCSTR to LPCWSTR
		USES_CONVERSION;
		LPCWSTR keyDataW = A2W(newHostName);

		LONG retval = RegOpenKeyEx(HKEY_LOCAL_MACHINE, regPath, 0, KEY_ALL_ACCESS, &hKey);

		if (retval == ERROR_SUCCESS) {
			printf("Success opening key.");

		}
		else {
			printf("Error opening key.");
			cout << retval;
		}
		retval = (RegSetValueEx(hKey, TEXT("HostName"), 0, REG_SZ, (BYTE*)keyDataW, lstrlen(keyDataW) + 17));

		if (retval == ERROR_SUCCESS){
			printf("Success setting key. ");
		}
		else {
			printf("Error setting key.");
		}
		retval = RegCloseKey(hKey);
	}