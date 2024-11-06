fun main()
{
    val str=readLine()!!
    val ch=readLine()!!
    var pos=-1
    for(i in 0..str.length-1)
    {
        if(str[i]==ch[0])
        {
            pos=i+1
            break
        }
    }
    if(pos==-1)print("Not Found")
    else print(pos)
}