fun main()
{
    var arr=IntArray(9){0}
    val N=readLine()!!.toInt()
    var lists=readLine()!!.trim().split(" ").map{it.toInt()}.toIntArray()
    for(i in 0..N-1)arr[lists[i]]++
    for(i in 1..8)print("${i} - ${arr[i]}\n")
}