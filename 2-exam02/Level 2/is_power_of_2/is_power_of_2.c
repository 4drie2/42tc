int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    return (n & (n - 1)) == 0;
}
int abpower1(unsigned int n){
    if (n == 0)
        return (0);
    return ((n & (n - 1)) == 0)
}
