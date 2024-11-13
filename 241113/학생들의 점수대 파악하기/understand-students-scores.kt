fun main()
{
    val n=readLine()!!.toInt()
    val scores=readLine()!!.trim().split(" ").map{it.toInt()}
    var arr=IntArray(11){0}
    for(i in 0..n-1)arr[scores[i]/10]++
    for(i in 10 downTo 1)
    {
        if(arr[i]>0)print("${i*10} - ${arr[i]}\n")
    }
}