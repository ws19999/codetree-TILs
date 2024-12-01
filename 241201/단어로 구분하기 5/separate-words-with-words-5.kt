fun main()
{
    val str=readLine()!!.split(" ")
    for(i in 1..str.size-1 step(2))print("${str[i]}\n")
}