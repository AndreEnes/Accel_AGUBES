 /***************************************************************************/
 #ifndef _NO_OS_I2C_H_
 #define _NO_OS_I2C_H_
  
 /******************************************************************************/
 /***************************** Include Files **********************************/
 /******************************************************************************/
  
 #include <stdint.h>
  
 /******************************************************************************/
 /*************************** Types Declarations *******************************/
 /******************************************************************************/
  
 struct no_os_i2c_platform_ops ;
  
 struct no_os_i2c_init_param {
     uint32_t    device_id;
     uint32_t    max_speed_hz;
     uint8_t     slave_address;
     const struct no_os_i2c_platform_ops *platform_ops;
     void        *extra;
 };
  
 struct no_os_i2c_desc {
     uint32_t    device_id;
     uint32_t    max_speed_hz;
     uint8_t     slave_address;
     const struct no_os_i2c_platform_ops *platform_ops;
     void        *extra;
 };
  
 struct no_os_i2c_platform_ops {
     int32_t (*i2c_ops_init)(struct no_os_i2c_desc **,
                 const struct no_os_i2c_init_param *);
     int32_t (*i2c_ops_write)(struct no_os_i2c_desc *, uint8_t *, uint8_t, uint8_t);
     int32_t (*i2c_ops_read)(struct no_os_i2c_desc *, uint8_t *, uint8_t, uint8_t);
     int32_t (*i2c_ops_remove)(struct no_os_i2c_desc *);
 };
  
 /******************************************************************************/
 /************************ Functions Declarations ******************************/
 /******************************************************************************/
  
 /* Initialize the I2C communication peripheral. */
 int32_t no_os_i2c_init(struct no_os_i2c_desc **desc,
                const struct no_os_i2c_init_param *param);
  
 /* Free the resources allocated by no_os_i2c_init(). */
 int32_t no_os_i2c_remove(struct no_os_i2c_desc *desc);
  
 /* Write data to a slave device. */
 int32_t no_os_i2c_write(struct no_os_i2c_desc *desc,
             uint8_t *data,
             uint8_t bytes_number,
             uint8_t stop_bit);
  
 /* Read data from a slave device. */
 int32_t no_os_i2c_read(struct no_os_i2c_desc *desc,
                uint8_t *data,
                uint8_t bytes_number,
                uint8_t stop_bit);
  
 #endif // _NO_OS_I2C_H_
