/*
 * This file is part of the FieldOpt project.
 *
 * Copyright (C) 2015-2015 Einar J.M. Baumann <einarjba@stud.ntnu.no>
 *
 * The code is largely based on ResOpt, created by  Aleksander O. Juell <aleksander.juell@ntnu.no>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */


#include "variable.h"

int Variable::next_id = 0;

Variable::Variable()
{
    m_id = next_id++;
    setName("no_name");
}

void Variable::emitException(ExceptionSeverity severity, ExceptionType type, QString message)
{
    VariableHandler* vh = new VariableHandler;
    connect(this, SIGNAL(warning(ExceptionSeverity, ExceptionType, QString)),
            vh, SLOT(handleException(ExceptionSeverity, ExceptionType, QString)));
    emit warning(severity, type, message);
    disconnect(this, SIGNAL(warning(ExceptionSeverity, ExceptionType, QString)),
            vh, SLOT(handleException(ExceptionSeverity, ExceptionType, QString)));
}