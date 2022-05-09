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
}
