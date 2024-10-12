fun main()
{
    var answer=""
    var num=0
    while(true)
    {
        val str=readLine()!!
        if(str=="0")break
        num+=1
        if(num%2==0)
        {
            if(num!=2)
            {
                answer+="\n"
            }
            answer+=str
        }
    }
    println(num)
    print(answer)
}