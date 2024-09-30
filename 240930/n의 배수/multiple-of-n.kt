fun main()
{
    val n=readLine()!!.toInt()
    for(i in 1..10)
    {
        if(i*n>=200)break
        print("${i*n} ")
        if((i*n)%10==0)break
    }
}