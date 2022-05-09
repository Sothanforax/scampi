#include <iostream>
#include "cpu.h"
#include "interface.h"

void dump_mem();
uint8_t memory[0xFFFF];

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
	if(cpu.EmuState() == 2){std::cout << "SS: Enter to increment P0" << std::endl;}
	while(cpu.EmuState() == 2){
		std::cin.get();
		cpu.Tick(memory[cpu.P0]);
		std::cout << "P0: 0x" << std::hex << cpu.P0 << " MEM: 0x" << static_cast<int>(memory[cpu.P0])  
			<< "\nP1: 0x" << std::hex << cpu.P1 
			<< "\nP2: 0x" << std::hex << cpu.P2 
			<< "\nP3: 0x" << std::hex << cpu.P3 
			<< "\nACC: 0x" << std::hex << static_cast<int>(cpu.ACC)
			<< "\nE: 0x" << std::hex << static_cast<int>(cpu.EXT) << std::endl;
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
