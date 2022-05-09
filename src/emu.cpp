#include <iostream>
#include "cpu.h"
#include "interface.h"

int main(){
	uint8_t memory[0xFFFF];
	Cpu cpu;
	cpu.Init();
	while(cpu.EmuState() == 0){
		cpu.Tick(memory[cpu.PCounterOut()]);
		if(cpu.PCounterOut() == sizeof(memory)/sizeof(uint8_t)){
			cpu.SetEmuState(1);
			std::cout << "Out of Memory, Execution Halted." << std::endl;
			std::cout << "Addr: 0x" << std::hex << sizeof(memory) / sizeof(uint8_t) << std::endl;
		}
}
	if(cpu.EmuState() == 2){std::cout << "SS: Enter to increment P0" << std::endl;}
	while(cpu.EmuState() == 2){
		std::cin.get();
		cpu.Tick(memory[cpu.PCounterOut()]);
		std::cout << "P0: 0x" << std::hex << cpu.PCounterOut();
		if(cpu.PCounterOut() == sizeof(memory)/sizeof(uint8_t)){
			cpu.SetEmuState(1);
			std::cout << std::endl << "Out of Memory, Execution Halted." << std::endl;
			std::cout << "Addr: 0x" << std::hex << sizeof(memory) / sizeof(uint8_t) << std::endl;
		}
	}
}
