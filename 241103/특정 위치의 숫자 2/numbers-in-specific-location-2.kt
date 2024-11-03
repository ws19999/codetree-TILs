fun main()
{
    val n=readLine()!!.toInt()
    val lists=readLine()!!.trim().split(" ").map{it.toInt()}
    var cnt=0
    var sums=0
    for(i in 0..n-1)
    {
        if(i%2==1)
        {
            sums+=lists[i]
            cnt++
        }
    }
    print("${sums} ${String.format("%.1f",sums.toDouble()/cnt.toDouble())}")
}