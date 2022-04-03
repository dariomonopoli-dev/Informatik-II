int recursivegcd(int x, int y)
{
    if (y==0)
    {
        return x;
    }
    else{
        return recursivegcd(y, x%y);
    }
}

int main()
{
    int result = recursivegcd(21, 7);
    printf("The gcd is %d", result);
}