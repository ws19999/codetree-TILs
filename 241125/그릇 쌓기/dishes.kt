fun main()
{
    val str=readLine()!!
    val len=str.length
    var answer=10
    for(i in 1..len-1)
    {
        if(str[i]==str[i-1])answer+=5
        else answer+=10
    }
    print(answer)
}