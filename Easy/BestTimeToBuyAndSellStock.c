int maxProfit(int* prices, int pricesSize) {
    int ret = 0;
    int buy = 10000;
    int sell = 0;

    for(int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < buy) 
        {
            buy = prices[i];
            sell = 0;
        }
        else
        {
            sell = prices[i];
        }
        ret = sell - buy > ret ? sell - buy : ret;
    }
    return ret;
}
