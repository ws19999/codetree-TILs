fun main()
{
    val str=readLine()!!
    for(i in 0..2)print(str[i])
    println()
    val len=str.length
    for(i in len-4..len-1)print(str[i])
}