fun main()
{
    val n=readLine()!!.toInt()
    val lists=readLine()!!.trim().split(" ").map{it.toInt()}
    var sums=0
    for(i in 0..n-1)
    {
        sums+=lists[i]
        if(sums>=200)
        {
            println(sums)
            print(String.format("%.1f",sums.toDouble()/(i+1)))
            break
        }
    }
}