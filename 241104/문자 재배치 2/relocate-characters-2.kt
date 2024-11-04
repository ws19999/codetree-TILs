fun main()
{
    val n=readLine()!!.toInt()
    var arr=readLine()!!.trim().split(" ")
    for(i in n-1 downTo 0)print("${arr[i]} ")
}