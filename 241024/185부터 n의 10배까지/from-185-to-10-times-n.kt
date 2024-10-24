fun main()
{
    val n=readLine()!!.toInt()
    var num=0
    for(i in 185..n*10)num += i
    print("${num} ")
    print(String.format("${num.toDouble()/(n*10-185+1)}",.1f))
    
}