#include <cstdint>
#include <menu.hh>
#include <program.hh>
#include <string>

extern "C" {
// TODO: Implement all the 9 items of reports
MenuItem *reportItems[] = {
  new MenuItem(
      9, 
      "Not yet implemented!",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: implement function body
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      8, 
      "Not yet implemented!",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: implement function body
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      7, 
      "Not yet implemented!",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: implement function body
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      6, 
      "Not yet implemented!",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: implement function body
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      5, 
      "Not yet implemented!",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: implement function body
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      4, 
      "Not yet implemented!",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: implement function body
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      3, 
      "Not yet implemented!",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: implement function body
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      2, 
      "Not yet implemented!",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: implement function body
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      1, 
      "Display the information of all the lists",
      [](Menu *, Program *ctx) -> CommandCodes {
        // TODO: Print detailed information for every node,
        printf("\n\u001b[4;34mPerson list:\u001b[0m");
        ctx->people->show();
        printf("\n\u001b[4;34mRegion list:\u001b[0m");
        ctx->regions->show();
        printf("\n\u001b[4;34mPlace list:\u001b[0m");
        ctx->places->show();
        printf("\n\u001b[4;34mClimate list:\u001b[0m");
        ctx->climates->show();
        printf("\n\u001b[4;34mRain list:\u001b[0m");
        ctx->rains->show();
        printf("\n\u001b[4;34mInstant list:\u001b[0m");
        ctx->instants->show();
        ctx->reports->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      0,
      "Back",
      [](Menu *, Program *) -> CommandCodes {
        return CommandCodes::EXIT;
      })
};

void DllExport setup(Program *program) {
  for (MenuItem *item : reportItems) {
    program->reports->addItem(item->withContext(program));
  }
}
}
