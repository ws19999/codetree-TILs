fun main()
{
    var c='A'
    val n=readLine()!!.toInt()
    for(i in n downTo 1)
    {
        for(j in 1..i)
        {
            print(c)
            c++
            if(c>'Z')c='A'
        }
        print("\n")
    }
}