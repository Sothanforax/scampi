#include <iostream>
#include <ostream>
#include <string>
#include "cpu.h"

void dump_mem();
uint8_t memory[0xFFFF];
/*Paging, and memory layout
*The address space is 16 bit, but divided into 16 pages of 4096 bytes each.
*Memory address layout:
*15-12 Page #
*11-0 Page Displacement.
*
*0 000
*P DDD
* aka: page 0 goes from 0000 to 0FFF
* page 1 goes from 1000 to 1FFF
* etc etc.
*/

int main(){
	Cpu cpu;
	cpu.Init();
	while(cpu.EmuState() == 0){
		cpu.Tick(memory[cpu.P0]);
		if(cpu.P0 == sizeof(memory)/sizeof(uint8_t)){
			cpu.SetEmuState(1);
			std::cout << "Out of Memory, Execution Halted." << std::endl;
			std::cout << "Addr: 0x" << std::hex << sizeof(memory) / sizeof(uint8_t) << std::endl;
		}
}
	while(cpu.EmuState() == 2){
		std::string dbgc;
		std::cout << "> ";
		std::getline(std::cin,dbgc);
		if(dbgc == "s"){
		cpu.Tick(memory[cpu.P0]);
		std::cout << "SINGLE STEP" << std::endl;
		std::cout << "P0: 0x" << std::hex << cpu.P0 << " MEM: 0x" << static_cast<int>(memory[cpu.P0])  
			<< "\nP1: 0x" << std::hex << cpu.P1 
			<< "\nP2: 0x" << std::hex << cpu.P2 
			<< "\nP3: 0x" << std::hex << cpu.P3 
			<< "\nACC: 0x" << std::hex << static_cast<int>(cpu.ACC)
			<< "\nE: 0x" << std::hex << static_cast<int>(cpu.EXT) << std::endl;
		}
		else if(dbgc == "h"||dbgc == "help"){
			std::cout << "Commands" << std::endl << "h/help: view help\nq/quit: quit debugger and emulator\nr: dump register contents\ne: examine memory at specified address\nx: resume eXecution of emulator, exiting the debugger" << std::endl;
		}
		else if(dbgc == "q"||dbgc == "quit"){
			return 0;
		}
		else if(dbgc == "r"){
			std::cout << "P0: 0x" << std::hex << cpu.P0  
			<< "\nP1: 0x" << std::hex << cpu.P1 
			<< "\nP2: 0x" << std::hex << cpu.P2 
			<< "\nP3: 0x" << std::hex << cpu.P3 
			<< "\nACC: 0x" << std::hex << static_cast<int>(cpu.ACC)
			<< "\nE: 0x" << std::hex << static_cast<int>(cpu.EXT) << std::endl;
		}
		else if(dbgc == "e"){
			int maddr;
			std::cout << "Addr: ";
			std::cin >> maddr;
			std::cout << "Memory at ADDR: " << std::hex <<memory[maddr];
			//std::cout << "\nMemory at Program Counter: " << std::hex << memory[cpu.P0];
		}
		else if(dbgc == "x"){
			cpu.SetEmuState(0);
		}
		else{
			std::cout << "Invalid debugger command: " << dbgc << std::endl;
			}

		if(cpu.P0 == sizeof(memory)/sizeof(uint8_t)){
			cpu.SetEmuState(1);
			std::cout << std::endl << "Out of Memory, Execution Halted." << std::endl;
			std::cout << "Addr: 0x" << std::hex << sizeof(memory) / sizeof(uint8_t) << std::endl;
		}
	}
}

void dump_mem(){
	for(int i=0;i<sizeof(memory)/sizeof(uint8_t);i++){
		std::cout << " 0x" << std::hex << static_cast<int>(memory[i]);
	}
}
