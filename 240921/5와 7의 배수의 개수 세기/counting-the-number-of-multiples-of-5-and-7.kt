fun main()
{
    val n=readLine()!!.toInt()
    val lists=readLine()!!.split(" ").map{it.toInt()}
    var five=0
    var seven=0
    for(i in 0..n-1)
    {
        if(lists[i]%5==0)five++
        if(lists[i]%7==0)seven++
    }
    println(five)
    println(seven)
}