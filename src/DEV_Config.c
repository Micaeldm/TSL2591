
#include "DEV_Config.h"
#include <time.h>
#include <unistd.h>

uint8_t DEV_SPI_Device = 0, DEV_I2C_Device = 0;
uint8_t I2C_ADDR;
/******************************************************************************
function:	GPIO Function initialization and transfer
parameter:
Info: Editar esta parte
******************************************************************************/

/*void DEV_GPIO_Mode(GPIO_TypeDef* GPIO_Port, UWORD Pin, UWORD mode)
{

       // 0:  INPT
       // 1:  OUTP


    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = Pin;
    if(mode == GPIO_MODE_INPUT || mode == 0){
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    }else if(mode == GPIO_MODE_OUTPUT_PP || mode == 1){
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    }else{
        GPIO_InitStruct.Mode = mode;
    }
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIO_Port, &GPIO_InitStruct);
}*/

/**
 * delay x ms
 **/
void DEV_Delay_ms(UDOUBLE xms) {
    // editar poner timer esp32
    // HAL_Delay(xms);
    usleep(1000 * xms);
}

void GPIO_Config(void) {
    // DEV_GPIO_Mode(INT_PIN, 0);
}

/******************************************************************************
function:	SPI Function initialization and transfer
parameter:
Info:
******************************************************************************/
void DEV_SPI_Init() {
#if DEV_SPI
    DEV_SPI_Device = 1;
#endif
}

void DEV_SPI_WriteByte(uint8_t Value) {
#if DEV_SPI

#endif
}

void DEV_SPI_Write_nByte(uint8_t * pData, uint32_t Len) {
#if DEV_SPI

#endif
}
/******************************************************************************
function:	I2C Function initialization and transfer
parameter:
Info:
******************************************************************************/
void DEV_I2C_Init(uint8_t Add) {
#if DEV_I2C
    DEV_I2C_Device = 1;
    I2C_ADDR = Add;
#endif
}

void I2C_Write_Byte(uint8_t Cmd, uint8_t value) {
#if DEV_I2C
    UBYTE Buf[1] = {0};
    UBYTE Buf1[1] = {0};
    UBYTE cmd_ = Cmd | value;
    Buf[0] = value;

    // Editar con i2c esp32

    // i2c_master_write_read_device(I2C_NUM_0, I2C_ADDR, &Cmd, 1, Buf, 1, 0x20);
    // i2c_master_write_read_device(I2C_NUM_0, I2C_ADDR, &value, 1, Buf1, 1, 0x20);
    i2c_master_write_to_device(I2C_NUM_0, I2C_ADDR, &Cmd, 1, pdMS_TO_TICKS(100));
    i2c_master_write_to_device(I2C_NUM_0, I2C_ADDR, &value, 1, pdMS_TO_TICKS(100));
    // i2c_master_write_read_device(I2C_NUM_0, I2C_ADDR, &value, 1, Buf, 1, 0x20);
    // HAL_I2C_Mem_Write(&hi2c1, I2C_ADDR, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 1, 0x20);
#endif
}

int I2C_Read_Byte(uint8_t Cmd) {
#if DEV_I2C
    UBYTE Buf[1] = {0};
    // Editar con i2c esp32
    // i2c_master_write_to_device(I2C_NUM_0, I2C_ADDR, &Cmd, 1, pdMS_TO_TICKS(100));
    // DEV_Delay_ms(10);
    // i2c_master_read_from_device(I2C_NUM_0, I2C_ADDR,  Buf,1, pdMS_TO_TICKS(100));
    i2c_master_write_read_device(I2C_NUM_0, I2C_ADDR, &Cmd, 1, Buf, 1, 0x20); // pdMS_TO_TICKS(1000)

    // HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR+1, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 1, 0x20);
    return Buf[0];
    //return 1;
#endif
}

int I2C_Read_Word(uint8_t Cmd) {
#if DEV_I2C
    UBYTE Buf[2] = {0, 0};
    // Editar con i2c esp32
    // i2c_master_write_to_device(I2C_NUM_0, I2C_ADDR, &Cmd, 1, pdMS_TO_TICKS(100));
    // DEV_Delay_ms(10);
    // i2c_master_read_from_device(I2C_NUM_0, I2C_ADDR,  Buf,2, pdMS_TO_TICKS(100));

   // i2c_master_write_read_device(I2C_NUM_0, I2C_ADDR, &Cmd, 1, Buf, 2, 0x20);
    // HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR+1, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 2, 0x20);

    // printf("Lux_buf_Low = %d\r\n",Buf[0]);
    // printf("Lux_buf_high= %d\r\n",Buf[1]);

    return ((Buf[1] << 8) | (Buf[0] & 0xff));
#endif
}
/******************************************************************************
function:	Module Initialize, the library and initialize the pins, SPI protocol
parameter:
Info:
******************************************************************************/
UBYTE DEV_ModuleInit(void) {
    GPIO_Config();
    DEV_I2C_Init(0x29); // 0x29 << 1
    return 0;
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
void DEV_ModuleExit(void) {
}

int DEV_Digital_Read(uint8_t _pin) {
    return gpio_get_level(_pin);
}
