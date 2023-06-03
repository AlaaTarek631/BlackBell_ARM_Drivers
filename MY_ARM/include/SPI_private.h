#ifndef     SPI_PRIVATE_H
#define     SPI_PRIVATE_H

typedef struct {
	volatile u32 CR1;
	volatile u32 Reserved1;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_t;

#define		 SPI1    ((volatile SPI_t *)0x40013000)
#define		 SPI2    ((volatile SPI_t *)0x40013800)
#define		 SPI3    ((volatile SPI_t *)0x40003C00)
#define		 SPI4    ((volatile SPI_t *)0x40013400)


#endif