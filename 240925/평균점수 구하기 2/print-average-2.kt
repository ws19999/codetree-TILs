fun main()
{
    val n=readLine()!!.toInt()
    val lists=readLine()!!.trim().split(" ").map{it.toDouble()}
    var num=0.0
    for(i in 0..n-1)
    {
        num+=lists[i]
    }
    print(String.format("%.1f",num/n))
}