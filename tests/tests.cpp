#include <vector>
#include <iostream>
#include <functional>

#include "tests.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

void initTests(void)
{
  // Body Contain Tests
  tests.push_back(BodyContainTest1);
  tests.push_back(BodyContainTest2);
  tests.push_back(BodyContainTest3);

}

int launchTests(void)
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}


// Было несколбко вариантов развития событий
//
// Запихнуть все три теста в один и вернуть общий результат трёх тестов
// Тоесть:
//     return object.testFunc(value1) && 
//            object.testFunc(value2) &&
//            object.testFunc(value3) 
//
// Это весьма не логично потому что если условно будет 1000 тестов в одной функции
// То я просто не смогу сразу узнать где находится моя ошибка
//
//
// Был вариант сделать wrapper, который бы возвращал ссылку на функцию
// Такое возможно сделать, но я не просто хочу получить адресс этой функции
// Я хочу получить адресс, предоставляя аргументы данной функции
// Примерно вот так
// 		&(func(TestCandleObject, TestVerifiableValue) 
// Но плюсы, да даже не плюсы, а я просто не могу понять как это реализовать
// Вроде вернуть адресс просто функции могу , а с аргументами проблема
// Я пробовал лямбды, но безуспешно
//
//
// Поэтому всё что написано ниже такой дичайший колхоз просто
// Это очень не красиво и очень не универсально по сравнению с wrapper(ом)
//



Candle BodyContainObject(241.12, 244.89, 233.89, 243.11);

static bool BodyContainTest1(void)
{
	// Тест проходит хотя значение оставляет желать лучшего	
	
	return BodyContainObject.body_contains(241.119999999999999); 
}

static bool BodyContainTest2(void)
{
	return BodyContainObject.body_contains(243.1100000000000001); 
}

static bool BodyContainTest3(void)
{
	return BodyContainObject.body_contains(242.2); 
}
