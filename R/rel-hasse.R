## This file is part of the 'agop' library.
##
## Copyright 2013-2014 Marek Gagolewski, Anna Cena
##
## 'agop' is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## 'agop' is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with 'agop'. If not, see <http://www.gnu.org/licenses/>.



#' @title
#' Hasse Diagrams
#'
#' @description
#' This function calculates the reflexive reduction
#' and a kind of transitive reduction which is useful for drawing Hasse
#' diagrams.
#'
#' @details
#' The input matrix \eqn{R} may not necessarily be acyclic/assymetric, i.e.
#' it can represent any totally preordered set (which induces an equivalence
#' relation on the underlying preordered set).
#' The algorithm implemented runs in \eqn{O(n^3)} time
#' and first determines the transitive closure of \eqn{R}.
#' If an irreflexive \eqn{R} is given, then the transitive closures
#' of \eqn{R} and of the resulting matrix are identical.
#' Moreover, if \eqn{R} is additionally acyclic, then this function
#' is equivalent to \code{\link{rel_reduction_transitive}}.
#'
#' @param R an object coercible to a 0-1 (logical) square matrix,
#' representing a binary relation on a finite set.
#'
#' @return The \code{rel_reduction_hasse} function
#' returns a logical square matrix. \code{\link{dimnames}}
#' of \code{R} are preserved.
#'
#' @examples
#' \dontrun{
#' # Let ord be a total preorder (a total and transitive binary relation)
#' # === Plot the Hasse diagram of ord ===
#' # ===  requires the igraph package  ===
#' library("igraph")
#' hasse <- graph.adjacency(rel_reduction_transitive(ord))
#' plot(hasse, layout=layout.fruchterman.reingold(hasse, dim=2))
#' }
#'
#' @family binary_relations
#' @rdname rel_transitive
#' @export
rel_reduction_hasse <- function(R)
{
   .Call("rel_reduction_hasse", as.matrix(R), PACKAGE="agop") # args checked internally
}
