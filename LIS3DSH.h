#ifndef LIS3DSH_h
#define LIS3DSH_h

#include <Arduino.h> // for byte data type

// register addresses

#define LIS3DSH_CTRL_REG1    	0x21
#define LIS3DSH_CTRL_REG3    	0x23
#define LIS3DSH_CTRL_REG4    	0x20
#define LIS3DSH_CTRL_REG5    	0x24
#define LIS3DSH_CTRL_REG6    	0x25
#define LIS3DSH_OUT_TEMP     	0x0C

#define LIS3DSH_OUT_X_L      	0x28
#define LIS3DSH_OUT_X_H      	0x29
#define LIS3DSH_OUT_Y_L      	0x2A
#define LIS3DSH_OUT_Y_H      	0x2B
#define LIS3DSH_OUT_Z_L      	0x2C
#define LIS3DSH_OUT_Z_H      	0x2D

#define LIS3DSH_FIFO_CTRL_REG	0x2E

#define LIS3DSH_SETT1			0x5B
#define LIS3DSH_MASK1_A			0x5A
#define LIS3DSH_MASK1_B			0x59
#define LIS3DSH_THRS1_1			0x57
#define LIS3DSH_ST1_1			0x40
#define LIS3DSH_ST1_2			0x41

class LIS3DSH
{
	public:
		LIS3DSH();

	public:
		uint8_t setSELState(uint8_t SELState);
		void enableDefault(void);
		void enableFast(void);
		void enableWakeup(void);
		void readAccel(int16_t *pX, int16_t *pY, int16_t *pZ);
		void readAccelX(int16_t *pX);
		void readAccelY(int16_t *pY);
		void readAccelZ(int16_t *pZ);
		void readTemperature(int8_t *pTemperature);
		void setFullScaleRange(const uint8_t FullScaleRange);
		void setBandwidth(const uint8_t Bandwidth);
		void setOutputDataRate(const uint8_t DataRate);

	protected:
		void writeReg(const uint8_t reg, const uint8_t value);
		uint8_t readReg(const uint8_t reg);

	protected:
		int I2CAddr;
};

#endif



