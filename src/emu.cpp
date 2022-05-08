#include <iostream>
#include "cpu.h"
#include "interface.h"

int main(){
	uint8_t memory[0xFFF];
	Cpu cpu;
	cpu.Init();
	while(cpu.EmuState() == 0){
		cpu.Tick(memory[cpu.PCounterOut()]);
		std::cout << "Tick " << cpu.PCounterOut() << std::endl;
}
}
