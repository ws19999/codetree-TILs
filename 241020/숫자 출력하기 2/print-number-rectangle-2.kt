fun main()
{
    val (n,m)=readLine()!!.trim().split(" ").map{it.toInt()}
    for(i in 1..n)
    {
        if(i%2==0)
        {
            for(j in i*m downTo (i-1)*m+1)print("${j} ")
            print("\n")
        }
        else
        {
            for(j in (i-1)*m+1..i*m)print("${j} ")
            print("\n")
        }
    }
}