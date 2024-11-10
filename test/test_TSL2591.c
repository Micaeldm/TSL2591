#include "unity.h"
#include "mock_DEV_Config.h"
#include "TSL2591.h"

/**
 * @brief
 *
 */

void test_TSL2591_ReadChannel0(void) {

    I2C_Read_Word_ExpectAndReturn(0xB4, 5);
    uint16_t valor = TSL2591_Read_Channel0();

    TEST_ASSERT_EQUAL_UINT16(5, valor);
}
/**
 * @brief
 *
 */
void test_TSL2591_ReadChannel1(void) {

    I2C_Read_Word_ExpectAndReturn(0xB6, 5);
    uint16_t valor = TSL2591_Read_Channel1();

    TEST_ASSERT_EQUAL_UINT16(5, valor);
}
/**
 * @brief
 *
 */
void test_TSL2591_DevModuleInit(void) {

    DEV_ModuleInit_ExpectAndReturn(0);
    uint8_t valor = DEV_ModuleInit();

    TEST_ASSERT_EQUAL_UINT16(0, valor);
}
/**
 * @brief
 *
 */
void test_TSL2591_Enable(void) {

    I2C_Write_Byte_Expect(0xA0, 0x03);

    TSL2591_Enable();
}
/**
 * @brief
 *
 */
void test_TSL2591_Disable(void) {

    I2C_Write_Byte_Expect(0xA0, 0x00);

    TSL2591_Disable();
}