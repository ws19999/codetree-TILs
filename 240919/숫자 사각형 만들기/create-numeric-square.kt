fun main()
{
    val n=readLine()!!.toInt()
    for(i in 9 downTo 10-n)
    {
        for(j in i downTo i+1-n)
        {
            if(j<=0)print("1 ")
            else print("${j} ")
        }
        print("\n")
    }
}