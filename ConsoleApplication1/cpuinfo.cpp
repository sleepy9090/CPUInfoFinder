// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#pragma comment(lib, "user32.lib")

using namespace System;
using namespace std;   // std::cout, std::cin

string getProcessorArchitecture(SYSTEM_INFO systemInfo);
string getProcessorType(SYSTEM_INFO systemInfo);
string isProcessorFeaturePresent(DWORD feature);

int main(array<System::String ^> ^args) {

	SYSTEM_INFO systemInfo;
	GetSystemInfo(&systemInfo);
	GetNativeSystemInfo(&systemInfo);

	cout << "CPU Hardware Information" << endl;
	cout << "   Processor architecture: " << getProcessorArchitecture(systemInfo) << endl;
	cout << "   Processor level: " << systemInfo.wProcessorLevel << endl;
	cout << "   Processor revision: " << systemInfo.wProcessorRevision << endl;
	//cout << "   OEM ID: " << systemInfo.dwOemId << endl;
	cout << "   Number of processors: " << systemInfo.dwNumberOfProcessors << endl;
	cout << "   Page size: " << systemInfo.dwPageSize << endl;
	cout << "   Processor type: " << getProcessorType(systemInfo) << endl;
	cout << "   Minimum application address: " << systemInfo.lpMinimumApplicationAddress << endl;
	cout << "   Maximum application address: " << systemInfo.lpMaximumApplicationAddress << endl;
	cout << "   Active processor mask: " << systemInfo.dwActiveProcessorMask << endl;
	cout << "   Allocation Granularity: " << systemInfo.dwAllocationGranularity << endl;
	//cout << "   Reserved: " << systemInfo.wReserved << endl;
	cout << "\n" << endl;
	cout << "Processor features" << endl;
	cout << "   PF_ARM_64BIT_LOADSTORE_ATOMIC: " << isProcessorFeaturePresent(PF_ARM_64BIT_LOADSTORE_ATOMIC) << endl;
	cout << "   PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE: " << isProcessorFeaturePresent(PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE) << endl;
	cout << "   PF_ARM_EXTERNAL_CACHE_AVAILABLE: " << isProcessorFeaturePresent(PF_ARM_EXTERNAL_CACHE_AVAILABLE) << endl;
	cout << "   PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE: " << isProcessorFeaturePresent(PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE) << endl;
	cout << "   PF_ARM_VFP_32_REGISTERS_AVAILABLE: " << isProcessorFeaturePresent(PF_ARM_VFP_32_REGISTERS_AVAILABLE) << endl;
	cout << "   PF_3DNOW_INSTRUCTIONS_AVAILABLE: " << isProcessorFeaturePresent(PF_3DNOW_INSTRUCTIONS_AVAILABLE) << endl;
	cout << "   PF_CHANNELS_ENABLED: " << isProcessorFeaturePresent(PF_CHANNELS_ENABLED) << endl;
	cout << "   PF_COMPARE_EXCHANGE_DOUBLE: " << isProcessorFeaturePresent(PF_COMPARE_EXCHANGE_DOUBLE) << endl;
	cout << "   PF_COMPARE_EXCHANGE128: " << isProcessorFeaturePresent(PF_COMPARE_EXCHANGE128) << endl;
	cout << "   PF_COMPARE64_EXCHANGE128: " << isProcessorFeaturePresent(PF_COMPARE64_EXCHANGE128) << endl;
	cout << "   PF_FASTFAIL_AVAILABLE: " << isProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE) << endl;
	cout << "   PF_FLOATING_POINT_EMULATED: " << isProcessorFeaturePresent(PF_FLOATING_POINT_EMULATED) << endl;
	cout << "   PF_FLOATING_POINT_PRECISION_ERRATA: " << isProcessorFeaturePresent(PF_FLOATING_POINT_PRECISION_ERRATA) << endl;
	cout << "   PF_MMX_INSTRUCTIONS_AVAILABLE: " << isProcessorFeaturePresent(PF_MMX_INSTRUCTIONS_AVAILABLE) << endl;
	cout << "   PF_NX_ENABLED: " << isProcessorFeaturePresent(PF_NX_ENABLED) << endl;
	cout << "   PF_PAE_ENABLED: " << isProcessorFeaturePresent(PF_PAE_ENABLED) << endl;
	cout << "   PF_RDTSC_INSTRUCTION_AVAILABLE: " << isProcessorFeaturePresent(PF_RDTSC_INSTRUCTION_AVAILABLE) << endl;
	cout << "   PF_RDWRFSGSBASE_AVAILABLE: " << isProcessorFeaturePresent(PF_RDWRFSGSBASE_AVAILABLE) << endl;
	cout << "   PF_SECOND_LEVEL_ADDRESS_TRANSLATION: " << isProcessorFeaturePresent(PF_SECOND_LEVEL_ADDRESS_TRANSLATION) << endl;
	cout << "   PF_SSE3_INSTRUCTIONS_AVAILABLE: " << isProcessorFeaturePresent(PF_SSE3_INSTRUCTIONS_AVAILABLE) << endl;
	cout << "   PF_VIRT_FIRMWARE_ENABLED: " << isProcessorFeaturePresent(PF_VIRT_FIRMWARE_ENABLED) << endl;
	cout << "   PF_XMMI_INSTRUCTIONS_AVAILABLE: " << isProcessorFeaturePresent(PF_XMMI_INSTRUCTIONS_AVAILABLE) << endl;
	cout << "   PF_XMMI64_INSTRUCTIONS_AVAILABLE: " << isProcessorFeaturePresent(PF_XMMI64_INSTRUCTIONS_AVAILABLE) << endl;
	cout << "   PF_XSAVE_ENABLED: " << isProcessorFeaturePresent(PF_XSAVE_ENABLED) << endl;

	cout << "\nPress any key to exit program." << endl;
	getch();
    return 0;
}

string isProcessorFeaturePresent(DWORD feature) {
	string isSupported = "Unsupported";

	if (IsProcessorFeaturePresent(feature) != 0) {
		isSupported = "Supported";
	}

	return isSupported;
}

string getProcessorType(SYSTEM_INFO systemInfo) {
	string processorType;

	switch (systemInfo.dwProcessorType) {
		case PROCESSOR_INTEL_386:
			processorType = "Intel 386";
			break;
		case PROCESSOR_INTEL_486:
			processorType = "Intel 486";
			break;
		case PROCESSOR_INTEL_PENTIUM:
			processorType = "Intel Pentium";
			break;
		case PROCESSOR_INTEL_IA64:
			processorType = "Intel IA64";
			break;
		case PROCESSOR_AMD_X8664:
			processorType = "AMD X86-64 (x64, AMD or Intel)";
			break;
		case PROCESSOR_MIPS_R4000:
			processorType = "MIPS R4000";
			break;
		case PROCESSOR_ALPHA_21064:
			processorType = "Alpha 2164";
			break;
		case PROCESSOR_PPC_601:
			processorType = "PPC 601";
			break;
		case PROCESSOR_PPC_603:
			processorType = "PPC 603";
			break;
		case PROCESSOR_PPC_604:
			processorType = "PPC 604";
			break;
		case PROCESSOR_PPC_620:
			processorType = "PPC 620";
			break;
		case PROCESSOR_HITACHI_SH3:
			processorType = "Hitachi SH3";
			break;
		case PROCESSOR_HITACHI_SH3E:
			processorType = "Hitachi SH3E";
			break;
		case PROCESSOR_HITACHI_SH4:
			processorType = "Hitachi SH4";
			break;
		case PROCESSOR_MOTOROLA_821:
			processorType = "Motorola 821";
			break;
		case PROCESSOR_SHx_SH3:
			processorType = "SHx-SH3";
			break;
		case PROCESSOR_SHx_SH4:
			processorType = "SHx-SH4";
			break;
		case PROCESSOR_STRONGARM:
			processorType = "StrongARM";
			break;
		case PROCESSOR_ARM720:
			processorType = "ARM-720";
			break;
		case PROCESSOR_ARM820:
			processorType = "ARM-820";
			break;
		case PROCESSOR_ARM920:
			processorType = "ARM-920";
			break;
		case PROCESSOR_ARM_7TDMI:
			processorType = "ARM-7TDMI";
			break;
		case PROCESSOR_OPTIL:
			processorType = "OPTIL";
			break;
		default:
			processorType = "Unknown processor type";
			break;
	}

	return processorType;
}

string getProcessorArchitecture(SYSTEM_INFO systemInfo) {
	string processorArchitecture;

	switch (systemInfo.wProcessorArchitecture) {
		case PROCESSOR_ARCHITECTURE_INTEL:
			processorArchitecture = "Intel (x86)";
			break;
		case PROCESSOR_ARCHITECTURE_MIPS:
			processorArchitecture = "MIPS";
			break;
		case PROCESSOR_ARCHITECTURE_ALPHA:
			processorArchitecture = "Alpha";
			break;
		case PROCESSOR_ARCHITECTURE_PPC:
			processorArchitecture = "PPC";
			break;
		case PROCESSOR_ARCHITECTURE_SHX:
			processorArchitecture = "SHx";
			break;
		case PROCESSOR_ARCHITECTURE_ARM:
			processorArchitecture = "ARM";
			break;
		case PROCESSOR_ARCHITECTURE_IA64:
			processorArchitecture = "IA64 (Intel Itanium-based)";
			break;
		case PROCESSOR_ARCHITECTURE_ALPHA64:
			processorArchitecture = "Alpha64";
			break;
		case PROCESSOR_ARCHITECTURE_MSIL:
			processorArchitecture = "MSIL";
			break;
		case PROCESSOR_ARCHITECTURE_AMD64:
			processorArchitecture = "AMD64 (x64, AMD or Intel)";
			break;
		case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64:
			processorArchitecture = "IA32/WIN64";
			break;
		default:
			processorArchitecture = "Unknown architecture";
			break;
	}

	return processorArchitecture;
}