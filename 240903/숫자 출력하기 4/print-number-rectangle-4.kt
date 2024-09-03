fun main()
{
    val (n,k) = readLine()!!.split(" ").map{it.toInt()}
    if(k==1)
    {
        for(i in 1..n)
        {
            for(j in 1..n)
            {
                print("${i} ")
            }
            print("\n")
        }
    }
    else if(k==2)
    {
        for(i in 1..n)
        {
            if(i%2==1)
            {
                for(j in 1..n)
                {
                    print("${j} ")
                }
            }
            else
            {
                for(j in n downTo 1)
                {
                    print("${j} ")
                }
            }
            print("\n")
        }
    }
    else
    {
        for(i in 1..n)
        {
            var temp=i
            for(j in 1..n)
            {
                print("${temp} ")
                temp+=i
            }
            print("\n")
        }
    }
}