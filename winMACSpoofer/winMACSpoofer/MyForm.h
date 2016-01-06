
#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
#define _WIN32_WINNT 0x0500
#define TOTALBYTES 8192
#define BYTEINCREMENT 4096

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif


#include <iostream>
#include <string>
#include <Windows.h>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <malloc.h>
#include <ctime>
#include <atlbase.h>
#include <msclr\marshal_cppstd.h>
#include <iomanip>
#include <sstream>
#include <atlstr.h>

#pragma comment(lib,"IPHlpApi.Lib")


using namespace std;
using namespace System;
using namespace System::Windows::Forms;


void setNewMac(); //Set the "Wi-Fi" adapter's new mac address

void revertToOriginalMac(); //change the mac Address back to the original

string getCurrentMAcAddress();//returns the curernt MAC Address of the active nic

string randomizeMAC();//returns a randomized MAC address

wstring getHostName();

void setNewHostName();

wstring queryKey();//Locates the subkey which holds the active "Wi-Fi" adapter

bool queryRegValue(wstring); //Find the subkey where the where the active "Wi-Fi" is located

LPCSTR getNetworkInfo();//Locate the active "Wi-Fi" adapter

#pragma once

//Global Variable that holds the final user changes to the MAC Address
string FINAL_MAC = "";
string HOST_NAME = "";

namespace winMACSpoofer {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Label^  label6;

	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Current MAC Address";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(146, 22);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(116, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(262, 131);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Set New MAC";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(145, 19);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(118, 21);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Random MAC Address";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(278, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Randomize\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 242);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Reset";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Enter New MAC Manually";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(145, 65);
			this->textBox3->MaxLength = 2;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(22, 20);
			this->textBox3->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(173, 65);
			this->textBox4->MaxLength = 2;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(22, 20);
			this->textBox4->TabIndex = 10;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(201, 65);
			this->textBox5->MaxLength = 2;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(22, 20);
			this->textBox5->TabIndex = 11;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(229, 65);
			this->textBox6->MaxLength = 2;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(22, 20);
			this->textBox6->TabIndex = 12;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(257, 65);
			this->textBox7->MaxLength = 2;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(22, 20);
			this->textBox7->TabIndex = 13;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(285, 65);
			this->textBox8->MaxLength = 2;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(22, 20);
			this->textBox8->TabIndex = 14;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(142, 98);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(65, 17);
			this->radioButton1->TabIndex = 15;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Random";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(213, 98);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(60, 17);
			this->radioButton2->TabIndex = 16;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Manual";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 102);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Set New MAC With :";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Location = System::Drawing::Point(4, 60);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(368, 160);
			this->groupBox1->TabIndex = 18;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Change The MAC Address";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(146, 242);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(226, 23);
			this->progressBar1->TabIndex = 19;
			// 
			// timer1
			// 
			this->timer1->Interval = 4;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(369, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(97, 13);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Current Host Name";
			// 
			// textBox9
			// 
			this->textBox9->Enabled = false;
			this->textBox9->Location = System::Drawing::Point(483, 24);
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(116, 20);
			this->textBox9->TabIndex = 21;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->textBox10);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Location = System::Drawing::Point(378, 60);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(260, 103);
			this->groupBox2->TabIndex = 22;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Change The Host Name";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 29);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Enter New Host Name";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(139, 26);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 20);
			this->textBox10->TabIndex = 1;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(138, 65);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(113, 23);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Change Host Name";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(641, 277);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		string currentMAC = getCurrentMAcAddress();
		String ^systemstring = gcnew String(currentMAC.c_str());
		textBox1->Text = systemstring;

		wstring currentHostName = getHostName();
		String ^currentHostNameSystem = gcnew String(currentHostName.c_str());
		textBox9->Text = currentHostNameSystem;
	}
	
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	FINAL_MAC = randomizeMAC();
	String ^systemstringRandom = gcnew String(FINAL_MAC.c_str());
	textBox2->Text = systemstringRandom;
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e){

	if (radioButton1->Checked){
		setNewMac();

		Sleep(4000);
		string currentMAC = getCurrentMAcAddress();
		String ^systemstring = gcnew String(currentMAC.c_str());
		textBox1->Text = systemstring;

	}
	else if (radioButton2->Checked){
		String ^manualMAC;
		manualMAC += textBox3->Text;
		manualMAC += "-";
		manualMAC += textBox4->Text;
		manualMAC += "-";
		manualMAC += textBox5->Text;
		manualMAC += "-";
		manualMAC += textBox6->Text;
		manualMAC += "-";
		manualMAC += textBox7->Text;
		manualMAC += "-";
		manualMAC += textBox8->Text;

		FINAL_MAC = msclr::interop::marshal_as<std::string>(manualMAC);
		setNewMac();

		Sleep(4000);
		string currentMAC = getCurrentMAcAddress();
		String ^systemstring = gcnew String(currentMAC.c_str());
		textBox1->Text = systemstring;

	}
	else{

	}
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e){
	//timer1->Start();
	//button3->Text = L"Test";
	revertToOriginalMac();
	
	Sleep(4000);
	string currentMAC = getCurrentMAcAddress();
	String ^systemstring = gcnew String(currentMAC.c_str());
	textBox1->Text = systemstring;

}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	progressBar1->Increment(1);
	
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e){

	String ^newHostName;
	newHostName += textBox10->Text;
	HOST_NAME = msclr::interop::marshal_as<std::string>(newHostName);
	setNewHostName();

	wstring currentHostName = getHostName();
	String ^currentHostNameSystem = gcnew String(currentHostName.c_str());
	textBox9->Text = currentHostNameSystem;

 }
	/*
		Functions for changing the MAC
	*/

	//Reset the MAC back to that of the computers nic
	void revertToOriginalMac(){

			 HKEY hKey;
			 wstring activeRegKey = queryKey();
			 LPCWSTR sk = activeRegKey.c_str();
			 USES_CONVERSION;
			 LPCWSTR activeRegKeyW = sk;

			 LPWSTR netAddr = TEXT("NetworkAddress");
			 LONG retval = RegOpenKeyEx(HKEY_LOCAL_MACHINE, activeRegKeyW, 0, KEY_ALL_ACCESS, &hKey);

			 if (retval == ERROR_SUCCESS) {
				 printf("Success opening key.");
			 }
			 else {
				 printf("Error opening key.");
			 }
			 retval = RegDeleteValue(hKey, netAddr);

			 retval = RegCloseKey(hKey);


			 system("netsh interface set interface ""Wi-Fi"" DISABLED");
			 system("netsh interface set interface ""Wi-Fi"" ENABLED");

		 }

	//Function that returns the current MAC Address
	string getCurrentMAcAddress(){
		/* Declare and initialize variables */

		PWCHAR networkAdap = NULL;
		PCHAR driverDesc = NULL;

		DWORD dwSize = 0;
		DWORD dwRetVal = 0;

		unsigned int i = 0;

		string currentMAC;

		// Set the flags to pass to GetAdaptersAddresses
		ULONG flags = GAA_FLAG_INCLUDE_PREFIX;

		// default to unspecified address family (both)
		ULONG family = AF_UNSPEC;

		LPVOID lpMsgBuf = NULL;

		PIP_ADAPTER_ADDRESSES pAddresses = NULL;
		ULONG outBufLen = 0;
		ULONG Iterations = 0;

		PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;

		// Allocate a 15 KB buffer to start with.
		outBufLen = WORKING_BUFFER_SIZE;

		do {

			pAddresses = (IP_ADAPTER_ADDRESSES *)MALLOC(outBufLen);
			if (pAddresses == NULL) {
				printf
					("Memory allocation failed for IP_ADAPTER_ADDRESSES struct\n");
				exit(1);
			}

			dwRetVal = GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);

			if (dwRetVal == ERROR_BUFFER_OVERFLOW) {
				FREE(pAddresses);
				pAddresses = NULL;
			}
			else {
				break;
			}

			Iterations++;

		} while ((dwRetVal == ERROR_BUFFER_OVERFLOW) && (Iterations < MAX_TRIES));

		if (dwRetVal == NO_ERROR) {
			// If successful, output some information from the data we received
			pCurrAddresses = pAddresses;

			//Cycles through the Network Adapters, ouputs name, type and operational status
			while (pCurrAddresses) {

				//check to see if network adapter is "Wi-fi"
				//printf("\tOperStatus: %ld\n", pCurrAddresses->OperStatus);
				networkAdap = pCurrAddresses->FriendlyName;
				if (pCurrAddresses->OperStatus == 1 && *networkAdap == 87){ //87 == "Wi-Fi"

					if (pCurrAddresses->PhysicalAddressLength != 0) {
						printf("\tPhysical address: ");
						for (i = 0; i < (int)pCurrAddresses->PhysicalAddressLength; i++) {
							if (i == (pCurrAddresses->PhysicalAddressLength - 1)){
								printf("%.2X\n", (int)pCurrAddresses->PhysicalAddress[i]);

								//Convert int to hex
								stringstream stream;
								stream << setw(2) << uppercase << hex << std::setfill('0')
									<< (int)pCurrAddresses->PhysicalAddress[i];
								currentMAC += stream.str();
							}
							else{
								printf("%.2X-", (int)pCurrAddresses->PhysicalAddress[i]);

								//Convert int to hex
								stringstream stream;
								stream << setw(2) << uppercase << hex << std::setfill('0')
									<< (int)pCurrAddresses->PhysicalAddress[i];
								currentMAC += stream.str();
								currentMAC += "-";
							}
						}
					}
				}
				pCurrAddresses = pCurrAddresses->Next;
			}

		}
		else {
			printf("Call to GetAdaptersAddresses failed with error: %d\n",
				dwRetVal);
			if (dwRetVal == ERROR_NO_DATA)
				printf("\tNo addresses were found for the requested parameters\n");
			else {

				if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
					FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
					// Default language
					(LPTSTR)& lpMsgBuf, 0, NULL)) {
					printf("\tError: %s", lpMsgBuf);
					LocalFree(lpMsgBuf);
					if (pAddresses)
						FREE(pAddresses);
					exit(1);
				}
			}
		}

		if (pAddresses) {
			FREE(pAddresses);
		}


		cout << currentMAC;
		return currentMAC;
	}

	//Function that returns a string of a random MAC addess
	string randomizeMAC(){
		srand(time(0)); //Seeds the rand() function
		string newMAC;
		char secondNibble[] = { 'A', 'E', '2', '6' };
		char newValArray[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
		for (int i = 0; i < 6; i++){

			newMAC += newValArray[rand() % 16];

			//Windows physical address second nibble is limited to 2, 6, A ,E
			if (i == 0)
				newMAC += secondNibble[rand() % 4];
			else
				newMAC += newValArray[rand() % 16];

			if (i < 5)
				newMAC += '-';

		}

		return newMAC;
	}

	//Function that spoofs a new MAC address
	void setNewMac(){

		HKEY hKey;
		wstring key = queryKey();

		string newMAC = FINAL_MAC;
		LPCSTR keyData = newMAC.c_str();

		//convert LPCSTR to LPCWSTR
		USES_CONVERSION;
		LPCWSTR skw = key.c_str();
		LPCWSTR keyDataW = A2W(keyData);
		cout << skw;
		LONG retval = RegOpenKeyEx(HKEY_LOCAL_MACHINE, skw, 0, KEY_ALL_ACCESS, &hKey);

		if (retval == ERROR_SUCCESS) {
			printf("Success opening key.");

		}
		else {
			printf("Error opening key.");
			cout << retval;
		}
		retval = (RegSetValueEx(hKey, TEXT("NetworkAddress"), 0, REG_SZ, (BYTE*)keyDataW, lstrlen(keyDataW) + 17));

		if (retval == ERROR_SUCCESS){
			printf("Success setting key. ");
		}
		else {
			printf("Error setting key.");
		}
		retval = RegCloseKey(hKey);


		system("netsh interface set interface ""Wi-Fi"" DISABLED");
		system("netsh interface set interface ""Wi-Fi"" ENABLED");

	}

	//Function that returns a path a registry key with the active nic
	wstring queryKey()
	{

		TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
		DWORD    cbName;                   // size of name string 
		TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
		DWORD    cchClassName = MAX_PATH;  // size of class string 
		DWORD    cSubKeys = 0;               // number of subkeys 
		DWORD    cbMaxSubKey;              // longest subkey size 
		DWORD    cchMaxClass;              // longest class string 
		DWORD    cValues;              // number of values for key 
		DWORD    cchMaxValue;          // longest value name 
		DWORD    cbMaxValueData;       // longest value data 
		DWORD    cbSecurityDescriptor; // size of security descriptor 
		FILETIME ftLastWriteTime;      // last write time 

		DWORD i, retCode;

		TCHAR  achValue[MAX_VALUE_NAME];
		DWORD cchValue = MAX_VALUE_NAME;

		HKEY hKey;
		LPCWSTR dir = TEXT("SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}");
		LONG checkReg = RegOpenKeyEx(HKEY_LOCAL_MACHINE, dir, 0, KEY_READ, &hKey);
		//cout << checkReg;

		if (checkReg == ERROR_SUCCESS)
		{
			cout << "Success opening key" << endl;
		}
		// Get the class name and the value count. 

		retCode = RegQueryInfoKey(
			hKey,                    // key handle 
			achClass,                // buffer for class name 
			&cchClassName,           // size of class string 
			NULL,                    // reserved 
			&cSubKeys,               // number of subkeys 
			&cbMaxSubKey,            // longest subkey size 
			&cchMaxClass,            // longest class string 
			&cValues,                // number of values for this key 
			&cchMaxValue,            // longest value name 
			&cbMaxValueData,         // longest value data 
			&cbSecurityDescriptor,   // security descriptor 
			&ftLastWriteTime);       // last write time 

		// Enumerate the subkeys, until RegEnumKeyEx fails.

		if (cSubKeys)
		{
			//printf("\nNumber of subkeys: %d\n", cSubKeys);

			for (i = 0; i < cSubKeys; i++)
			{
				cbName = MAX_KEY_LENGTH;
				retCode = RegEnumKeyEx(hKey, i, achKey, &cbName, NULL, NULL, NULL, &ftLastWriteTime);
				wstring key;

				if (retCode == ERROR_SUCCESS)
				{

					_tprintf(TEXT("(%d) %s\n"), i + 1, achKey);

					wstring subKey = achKey;

					wstring key = TEXT("SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}\\" + subKey);
					wcout << key;
					//Convert string to windows data type
					LPCWSTR findKey = key.c_str();
					cout << findKey;
					//return bool
					if (queryRegValue(subKey) == true)
						return key;
				};
			}
		}
	}


	//Find the subkey where the where the active "Wi-Fi" is located
	bool queryRegValue(wstring subKey){

		//set up our variables and buffers.
		DWORD dwType = REG_SZ;
		TCHAR szVersion[1024];
		DWORD dwDataSize = MAX_VALUE_NAME;
		memset(szVersion, 0, 32);
		wstring key = TEXT("SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}\\" + subKey);

		wcout << key << endl;
		//Convert string to windows data type
		LPCWSTR findKey = key.c_str();

		// open the key for reading.
		HKEY hkeyDXVer;
		long lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, findKey, 0, KEY_READ, &hkeyDXVer);

		cout << lResult;
		if (ERROR_SUCCESS == lResult)
		{

			LPCWSTR type = TEXT("NetCfgInstanceId");

			// read the version value
			lResult = RegQueryValueExW(hkeyDXVer, type, 0, &dwType, (PBYTE)szVersion, &dwDataSize);
			cout << lResult;
			if (ERROR_SUCCESS == lResult)
			{
				cout << szVersion;
				string netInfo = getNetworkInfo();
				TCHAR netInfoW[1024];
				_tcscpy_s(netInfoW, CA2T(netInfo.c_str()));
				wcout << "netinfo =" << netInfoW << " netInstId = " << szVersion << endl;
				
				if (*netInfoW == *szVersion){
					cout << "NetCfgInstanceId = " << szVersion << endl;
					return true;
				}
			}
		}
		return false;
	}
	//Function that returns the current Host Name
	wstring getHostName(){

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

	void setNewHostName(){

		HKEY hKey;
		
		LPCWSTR regPath = TEXT("SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters");
		LPCSTR newHostName = HOST_NAME.c_str();
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

	//Access the network Information (operStatus, friendlyname, adaptername)
	LPCSTR getNetworkInfo(){


		/* Declare and initialize variables */

		PWCHAR networkAdap = NULL;
		PCHAR driverDesc = NULL;

		DWORD dwSize = 0;
		DWORD dwRetVal = 0;

		unsigned int i = 0;

		// Set the flags to pass to GetAdaptersAddresses
		ULONG flags = GAA_FLAG_INCLUDE_PREFIX;

		// default to unspecified address family (both)
		ULONG family = AF_UNSPEC;

		LPVOID lpMsgBuf = NULL;

		PIP_ADAPTER_ADDRESSES pAddresses = NULL;
		ULONG outBufLen = 0;
		ULONG Iterations = 0;

		PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;

		// Allocate a 15 KB buffer to start with.
		outBufLen = WORKING_BUFFER_SIZE;

		//Name of the active Wi-Fi adapter
		LPCSTR adapName = NULL;
		do {

			pAddresses = (IP_ADAPTER_ADDRESSES *)MALLOC(outBufLen);
			if (pAddresses == NULL) {
				printf
					("Memory allocation failed for IP_ADAPTER_ADDRESSES struct\n");
				exit(1);
			}

			dwRetVal =
				GetAdaptersAddresses(family, flags, NULL, pAddresses, &outBufLen);

			if (dwRetVal == ERROR_BUFFER_OVERFLOW) {
				FREE(pAddresses);
				pAddresses = NULL;
			}
			else {
				break;
			}

			Iterations++;

		} while ((dwRetVal == ERROR_BUFFER_OVERFLOW) && (Iterations < MAX_TRIES));

		if (dwRetVal == NO_ERROR) {
			// If successful, output some information from the data we received
			pCurrAddresses = pAddresses;

			//Cycles through the Network Adapters, ouputs name, type and operational status
			while (pCurrAddresses) {

				printf("\tAdapter name: %s\n", pCurrAddresses->AdapterName);
				printf("\tDescription: %wS\n", pCurrAddresses->Description);
				printf("\tFriendly name: %wS\n", pCurrAddresses->FriendlyName);

				if (pCurrAddresses->PhysicalAddressLength != 0) {
					printf("\tPhysical address: ");
					for (i = 0; i < (int)pCurrAddresses->PhysicalAddressLength;
						i++) {
						if (i == (pCurrAddresses->PhysicalAddressLength - 1))
							printf("%.2X\n",
							(int)pCurrAddresses->PhysicalAddress[i]);
						else
							printf("%.2X-",
							(int)pCurrAddresses->PhysicalAddress[i]);
					}
				}

				//check to see if network adapter is "Wi-fi"
				//printf("\tOperStatus: %ld\n", pCurrAddresses->OperStatus);

				networkAdap = pCurrAddresses->FriendlyName;
				if (pCurrAddresses->OperStatus == 1 && *networkAdap == 87){ //87 == "Wi-Fi"
					//printf("\t***Success******8:  Friendly name == %wS\n", pCurrAddresses->FriendlyName);
					cout << pCurrAddresses->AdapterName << endl;
					driverDesc = pCurrAddresses->AdapterName;
					adapName = pCurrAddresses->AdapterName;
					return adapName;
				}

				pCurrAddresses = pCurrAddresses->Next;
			}

		}
		else {
			printf("Call to GetAdaptersAddresses failed with error: %d\n",
				dwRetVal);
			if (dwRetVal == ERROR_NO_DATA)
				printf("\tNo addresses were found for the requested parameters\n");
			else {

				if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
					FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					NULL, dwRetVal, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
					// Default language
					(LPTSTR)& lpMsgBuf, 0, NULL)) {
					printf("\tError: %s", lpMsgBuf);
					LocalFree(lpMsgBuf);
					if (pAddresses)
						FREE(pAddresses);
					exit(1);
				}
			}
		}

		if (pAddresses) {
			FREE(pAddresses);
		}
		return 0;

	}

};

}