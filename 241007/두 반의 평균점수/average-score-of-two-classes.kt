fun main()
{
    val n=readLine()!!.toInt()
    var lists=readLine()!!.trim().split(" ").map{it.toInt()}
    val (a,b)=readLine()!!.trim().split(" ").map{it.toInt()}
    print(String.format("${(lists[a-1].toDouble()+lists[b-1].toDouble())/2}",.1f))
}