#include <SFML/Graphics.hpp>
#include <iostream>
#include "Stack.h"
#define X 1000
#define Y 800
#define LX 5000
#define LY 4000
#define FSIZE 12
using namespace sf;

int main()
{
    while (true)
    {
        system("clear");

        Stack main;

#pragma region request

        std::cout << "Enter instructions(" << main.GetListOfCommands() << ")(Enter END for a end):" << std::endl;

        while (true)
        {
            std::string inst;
            std::cin >> inst;
            if (inst == "END")
            {
                break;
            }
            else if (main.IsCommand(inst))
            {
                main.Command(inst);
            }
            else
                std::cout << "Invalid instruction!" << std::endl;
        }

#pragma endregion

        float scalefunc = 1;
        float accuracy = 0.01;

        Vector2f startx(-(LX - X) / 2, Y / 2);
        Vector2f starty(X / 2, (LY + Y) / 2);
        Vector2f start(X / 2, Y / 2);
        Vector2f endx((LX + X) / 2, Y / 2);
        Vector2f endy(X / 2, -(LY - Y) / 2);

        RenderWindow window(VideoMode(X, Y), "SFML works!");

        float scalegrid = 20;

        Font font;

        font.loadFromFile("Ubuntu-L.ttf");
        Vector2i mouseposprev(0, 0);
        Vector2i deltapos(0, 0);

        bool buttonpressed = false;

        while (window.isOpen())
        {
            mouseposprev = Mouse::getPosition();

            Event event;

            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                else if (event.type == Event::MouseWheelScrolled)
                {
                    if (event.mouseWheelScroll.wheel == Mouse::VerticalWheel)
                    {
                        scalegrid += event.mouseWheelScroll.delta * 2 * scalegrid / 50;
                        if (scalegrid < 3)
                            scalegrid = 3;
                    }
                }
                else if (event.type == Event::MouseButtonPressed)
                {
                    buttonpressed = true;
                }
                else if (event.type == Event::MouseButtonReleased)
                {
                    buttonpressed = false;
                }
            }

            if (buttonpressed)
            {
                start.x += deltapos.x;
                start.y += deltapos.y;
                starty.x += deltapos.x;
                starty.y += deltapos.y;
                startx.x += deltapos.x;
                startx.y += deltapos.y;
                endx.x += deltapos.x;
                endx.y += deltapos.y;
                endy.x += deltapos.x;
                endy.y += deltapos.y;
            }
#pragma region func

            int countelements = (int)(5000);

            CircleShape func[countelements];

            for (int i = 0; i < countelements; i++)
            {
                float funcx = ((float)i - (float)countelements / 2) * accuracy;
                func[i].setPosition(start.x + funcx * scalegrid - scalefunc, start.y - main.Execute(funcx) * scalegrid - scalefunc);
                func[i].setRadius(scalefunc);
            }

#pragma endregion
#pragma region gridlines

            RectangleShape deklineX(Vector2f(LX, 2));
            deklineX.setPosition(startx);

            RectangleShape deklineY(Vector2f(2, LY));
            deklineY.setPosition(endy);

            VertexArray dekplane(Lines, 8);

#pragma region fillpos

            dekplane[0].position = endy;
            dekplane[1].position = Vector2f(endy.x - 7, endy.y + 7);
            dekplane[2].position = endy;
            dekplane[3].position = Vector2f(endy.x + 7, endy.y + 7);
            dekplane[4].position = endx;
            dekplane[5].position = Vector2f(endx.x - 7, endx.y - 7);
            dekplane[6].position = endx;
            dekplane[7].position = Vector2f(endx.x - 7, endx.y + 7);

#pragma endregion

            int countgridlinesX = LX / scalegrid / 2;
            int countgridlinesY = LY / scalegrid / 2;

            VertexArray gridXP(Lines, countgridlinesX * 2);
            VertexArray gridXI(Lines, countgridlinesX * 2);
            VertexArray gridYP(Lines, countgridlinesY * 2);
            VertexArray gridYI(Lines, countgridlinesY * 2);

            for (int i = 0; i < countgridlinesX; i++)
            {
                gridXP[i * 2].position = Vector2f(start.x + (i + 1) * scalegrid, start.y + LY / 2);
                gridXP[i * 2 + 1].position = Vector2f(start.x + (i + 1) * scalegrid, start.y - LY / 2);
            }

            for (int i = 0; i < countgridlinesX; i++)
            {
                gridXI[i * 2].position = Vector2f(start.x - (i + 1) * scalegrid, start.y + LY / 2);
                gridXI[i * 2 + 1].position = Vector2f(start.x - (i + 1) * scalegrid, start.y - LY / 2);
            }

            for (int i = 0; i < countgridlinesY; i++)
            {
                gridYP[i * 2].position = Vector2f(start.x + LX / 2, start.y + (i + 1) * scalegrid);
                gridYP[i * 2 + 1].position = Vector2f(start.x - LX / 2, start.y + (i + 1) * scalegrid);
            }

            for (int i = 0; i < countgridlinesY; i++)
            {
                gridYI[i * 2].position = Vector2f(start.x + LX / 2, start.y - (i + 1) * scalegrid);
                gridYI[i * 2 + 1].position = Vector2f(start.x - LX / 2, start.y - (i + 1) * scalegrid);
            }

#pragma endregion
#pragma region signgrid

            Text signO("0", font, FSIZE);

            signO.setPosition(start.x - 10, start.y);

            Text signgridXP[countgridlinesX];

            for (int i = 0; i < countgridlinesX; i++)
            {
                signgridXP[i].setString(std::to_string((i + 1)));
                signgridXP[i].setPosition(start.x + (i + 1) * scalegrid, start.y + 7);
                signgridXP[i].setCharacterSize(FSIZE);
                signgridXP[i].setFont(font);
            }

            Text signgridXI[countgridlinesX];

            for (int i = 0; i < countgridlinesX; i++)
            {
                signgridXI[i].setString(std::to_string(-(i + 1)));
                signgridXI[i].setPosition(start.x - (i + 1) * scalegrid, start.y + 7);
                signgridXI[i].setCharacterSize(FSIZE);
                signgridXI[i].setFont(font);
            }

            Text signgridYP[countgridlinesY];

            for (int i = 0; i < countgridlinesY; i++)
            {
                signgridYP[i].setString(std::to_string((i + 1)));
                signgridYP[i].setPosition(start.x - 20, start.y - (i + 1) * scalegrid);
                signgridYP[i].setCharacterSize(FSIZE);
                signgridYP[i].setFont(font);
            }

            Text signgridYI[countgridlinesY];

            for (int i = 0; i < countgridlinesY; i++)
            {
                signgridYI[i].setString(std::to_string(-(i + 1)));
                signgridYI[i].setPosition(start.x - 20, start.y + (i + 1) * scalegrid);
                signgridYI[i].setCharacterSize(FSIZE);
                signgridYI[i].setFont(font);
            }
#pragma endregion
#pragma region draw

            window.clear();
            window.draw(deklineX);
            window.draw(deklineY);
            window.draw(dekplane);
            window.draw(gridXP);
            window.draw(gridXI);
            window.draw(gridYP);
            window.draw(gridYI);
            window.draw(signO);

            for (int i = 0; i < countgridlinesX; i++)
            {
                window.draw(signgridXP[i]);
                window.draw(signgridXI[i]);
            }

            for (int i = 0; i < countgridlinesY; i++)
            {
                window.draw(signgridYP[i]);
                window.draw(signgridYI[i]);
            }

            for (int i = 0; i < countelements; i++)
            {
                window.draw(func[i]);
            }

            window.display();

#pragma endregion

            deltapos = Vector2i(Mouse::getPosition().x - mouseposprev.x, Mouse::getPosition().y - mouseposprev.y);
        }
    }
}