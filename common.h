/* 将1字节BCD数据转换为16进制数据 */
#define _BCD_TO_HEX(val)     (((val) & 0x0f) + ((val) >> 4) * 10)

/* 将1字节16进制数据转换为BCD数据 */
#define _HEX_TO_BCD(val)     ((((val) / 10) << 4) + (val) % 10)

/* 把符号转换为字符串 */
#define _STR(s)               #s

#define min(x, y)               (((x) < (y)) ? (x) : (y))
#define max(x, y)               (((x) < (y)) ? (y) : (x))
#define abs(x)      (((x) >= 0) ? (x) : (-x))

/* 计算数组元素个数 */
#define _NELEMENTS(array)               (sizeof (array) / sizeof ((array) [0]))

/* 计算结构体成员的大小 */
#define _MEMBER_SIZE(structure, member)  (sizeof(((structure *)0)->member))

/* 求结构体成员的偏移 */
#define _OFFSET(structure, member)    ((size_t)(&(((structure *)0)->member)))


/* 取2-byte整数的高位byte */
#define _MSB(x)       (((x) >> 8) & 0xff)

/* 取2-byte整数的低位byte */
#define _LSB(x)       ((x) & 0xff)

/* 取2-word整数的高位word */
#define _MSW(x)       (((x) >> 16) & 0xffff)

/* 取2-word整数的低位word */
#define _LSW(x)       ((x) & 0xffff)

/* 交换32-bit整数的高位word和低位word */
#define _WORDSWAP(x)  (_MSW(x) | (_LSW(x) << 16))

