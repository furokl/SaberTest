# SaberTest
<p align="right">
  <picture>
    <img alt="YOUR-ALT-TEXT" src="https://img.hhcdn.ru/employer-logo/4300269.jpeg" width=100 height=100>
  </picture>
</p>

<details>
<summary>Техническое задание</summary>

<p>Реализуйте функции сериализации и десериализации двусвязного списка, заданного следующим образом:</p>
  
```C++
class ListNode
{
public ListNode Prev;
    public ListNode Next;
    public ListNode Rand; // произвольный элемент внутри списка
    public string Data;
}

class ListRand
{
    public ListNode Head;
    public ListNode Tail;
    public int Count;

    public void Serialize(FileStream s)
    {
    }

    public void Deserialize(FileStream s)
    {
    }
}
``` 
Примечание: 
<p>Сериализация подразумевает сохранение и восстановление полной структуры списка, включая взаимное соотношение его элементов между собой — в том числе ссылок на Rand элементы.</p>
</details>

<details>
<summary>Для сборки проекта</summary>
  
```txt
cd "repository_path"\SaberTest
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ..

Используйте cmake --help, чтобы отобразить список возможных платформ
```
</details>
