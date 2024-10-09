fun main()
{
    for(i in 1..5)
    {
        val arr=readLine()!!.split(" ").map{it.toInt()}
        var ans=0
        for(j in 0..3)ans+=arr[j]
        println(ans)
    }
}