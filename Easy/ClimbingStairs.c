unsigned long long int orderPolynomial(unsigned long long int input, unsigned long long int stop)              
{                              
    unsigned long long int x = input; 
    unsigned long long int ret = 1;             
    while (x > stop) 
    { 
        ret *= x;  
        x -= 1;
    };     
    return ret;   
}

int climbStairs(int n) {
    unsigned long long int ones = n % 2;
    unsigned long long int twos = n >> 1;

    unsigned long long int ret = 0;
    while (ones < n + 1)
    {
        if (ones > twos)
        {
            ret += orderPolynomial(ones + twos, ones) / orderPolynomial(twos, 0);
        }
        else 
        {
            ret += orderPolynomial(ones + twos, twos) / orderPolynomial(ones, 0);
        }
        
        printf("1(%llu;%llu): %llu\n", ones, twos, orderPolynomial(ones + twos, 0));
        ones+=2;
        twos-=1;
    }
    
    return ret;
}
