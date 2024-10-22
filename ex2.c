using System;

public class VerificadorDeFibonacci
{
    public static bool EhFibonacci(int numero)
    {
        int a = 0, b = 1;
        while (b < numero)
        {
            int temp = a;
            a = b;
            b = temp + b;
        }
        return b == numero;
    }

    public static void Main()
    {
        Console.Write("Digite um número: ");
        int num = Convert.ToInt32(Console.ReadLine());

        if (EhFibonacci(num))
        {
            Console.WriteLine($"{num} pertence à sequência de Fibonacci.");
        }
        else
        {
            Console.WriteLine($"{num} não pertence à sequência de Fibonacci.");
        }
    }
}