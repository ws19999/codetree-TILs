fun main()
{
    val n=readLine()!!.toInt()
    var sums=0
    val temp=readLine()!!.trim()?.split(" ").map{it.toInt()}
    for(i in 0..n-1)
    {
        sums+=temp[i]
        if(temp[i]>=100)
        {
            println(sums)
            println("${String.format("%.1f",sums.toDouble()/(i+1))}")
            break
        }
    }
}