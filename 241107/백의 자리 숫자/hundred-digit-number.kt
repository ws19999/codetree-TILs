fun main()
{
    val n=readLine()!!.toInt()
    var arr=IntArray(10){0}
    val lists=readLine()!!.trim().split(" ").map{it.toInt()}
    for(i in 0..n-1)arr[(lists[i]/100)%10]++
    for(i in 0..9)
    {
        if(arr[i]>0)print("${i} - ${arr[i]}\n")
    }
}