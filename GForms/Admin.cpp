#include "Admin.h"

void Admin::create_quiz(const std::string& filename) {
     m_form.create_form(filename);
 }

void Admin::preview_quiz (const std::string& filename) {
     m_form.preview_form(filename);
 }

void Admin::preview_quizs () {
     m_form.preview_questionaries();
 }
 