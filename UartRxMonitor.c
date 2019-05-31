/* 串口接收监控，由空闲时间判定帧结束，需在定时中断中调用，ms-定时间隔 */
void UartRxMonitor(unsigned char ms)
{
    static unsigned char cntbkp = 0;
    static unsigned char idletmr = 0;

    if (cntRxd > 0)  //接收计数器大于零时，监控总线空闲时间
    {
        if (cntbkp != cntRxd)  //接收计数器改变，即刚接收到数据时，清零空闲计时
        {
            cntbkp = cntRxd;
            idletmr = 0;
        }
        else                      //接收计数器未改变，即总线空闲时，累积空闲时间
        {
            if (idletmr < 30)  //空闲计时小于30ms时，持续累加
            {
                idletmr += ms;

                if (idletmr >= 30)  //空闲时间达到30ms时，即判定为一帧接收完毕
                {
                    flagFrame = 1;  //设置帧接收完成标志
                }
            }
        }
    }
    else
    {
        cntbkp = 0;
    }
}
