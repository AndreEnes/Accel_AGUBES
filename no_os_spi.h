/***************************************************************************/
 #ifndef _NO_OS_SPI_H_
 #define _NO_OS_SPI_H_
  
 /******************************************************************************/
 /***************************** Include Files **********************************/
 /******************************************************************************/
  
 #include <stdint.h>
  
 /******************************************************************************/
 /********************** Macros and Constants Definitions **********************/
 /******************************************************************************/
  
 #define NO_OS_SPI_CPHA  0x01
 #define NO_OS_SPI_CPOL  0x02
  
 /******************************************************************************/
 /*************************** Types Declarations *******************************/
 /******************************************************************************/
  
 enum no_os_spi_mode {
     NO_OS_SPI_MODE_0 = (0 | 0),
     NO_OS_SPI_MODE_1 = (0 | NO_OS_SPI_CPHA),
     NO_OS_SPI_MODE_2 = (NO_OS_SPI_CPOL | 0),
     NO_OS_SPI_MODE_3 = (NO_OS_SPI_CPOL | NO_OS_SPI_CPHA)
 };
  
 enum no_os_spi_bit_order {
     NO_OS_SPI_BIT_ORDER_MSB_FIRST = 0,
     NO_OS_SPI_BIT_ORDER_LSB_FIRST = 1,
 };
  
 struct no_os_spi_msg {
     uint8_t         *tx_buff;
     uint8_t         *rx_buff;
     uint32_t        bytes_number;
     uint8_t         cs_change;
     uint32_t        cs_change_delay;
     uint32_t        cs_delay_first;
     uint32_t        cs_delay_last;
 };
  
 struct no_os_spi_platform_ops ;
  
 struct no_os_spi_init_param {
     uint32_t    device_id;
     uint32_t    max_speed_hz;
     uint8_t     chip_select;
     enum no_os_spi_mode mode;
     enum no_os_spi_bit_order    bit_order;
     const struct no_os_spi_platform_ops *platform_ops;
     void        *extra;
     struct no_os_spi_desc *parent;
 };
  
 struct no_os_spi_desc {
     uint32_t    device_id;
     uint32_t    max_speed_hz;
     uint8_t     chip_select;
     enum no_os_spi_mode mode;
     enum no_os_spi_bit_order    bit_order;
     const struct no_os_spi_platform_ops *platform_ops;
     void        *extra;
     struct no_os_spi_desc *parent;
 };
  
 struct no_os_spi_platform_ops {
     int32_t (*init)(struct no_os_spi_desc **, const struct no_os_spi_init_param *);
     int32_t (*write_and_read)(struct no_os_spi_desc *, uint8_t *, uint16_t);
     int32_t (*transfer)(struct no_os_spi_desc *, struct no_os_spi_msg *, uint32_t);
     int32_t (*remove)(struct no_os_spi_desc *);
 };
  
 /******************************************************************************/
 /************************ Functions Declarations ******************************/
 /******************************************************************************/
  
 /* Initialize the SPI communication peripheral. */
 int32_t no_os_spi_init(struct no_os_spi_desc **desc,
                const struct no_os_spi_init_param *param);
  
 /* Free the resources allocated by no_os_spi_init(). */
 int32_t no_os_spi_remove(struct no_os_spi_desc *desc);
  
 /* Write and read data to/from SPI. */
 int32_t no_os_spi_write_and_read(struct no_os_spi_desc *desc,
                  uint8_t *data,
                  uint16_t bytes_number);
  
 /* Iterate over the spi_msg array and send all messages at once */
 int32_t no_os_spi_transfer(struct no_os_spi_desc *desc,
                struct no_os_spi_msg *msgs,
                uint32_t len);
  
  
 #endif // _NO_OS_SPI_H_
